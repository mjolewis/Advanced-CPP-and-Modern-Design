//
// Illustrate how to use custom deleters with shared pointers. A deleter is a callable object
// that executes some code before an object goes out of scope. These can be used to clean up
// system resources.
//
// NOTE - The code below uses the file access mode string "a+", which allows us to create a new
// file if one doesn't exist and append to and existing file.
//
// Created by Michael Lewis on 6/23/23.
//

#include <iostream>
#include <memory>

// Function object that acts as custom deleter for a std::FILE object
class FileFinalizer
{
public:
    FileFinalizer() = default;

    // Operator overload for function object
    void operator()(std::FILE* file) {
        if (file == nullptr)
        {
            std::cout << "File did not open" << std::endl;
        }
        else
        {
            std::fclose(file);
            std::cout << "File has been closed" << std::endl;
        }
    }
};

// Free function that acts as a custom deleter for a std::FILE object
void functionFinalizer(std::FILE* file) {
    if (file == nullptr)
    {
        std::cout << "File did not open" << std::endl;
    }
    else
    {
        std::fclose(file);
        std::cout << "File has been closed" << std::endl;
    }
}

// Note: std::fstream has a destructor that closes the file, so using C-style code below
// to illustrate the custom destructor
int main()
{
    {
        // Create a file for read/write and used a function object as a custom deleter to clean up resources
        try
        {
            std::FILE* myFile = std::fopen("./myFile.txt", "a+");
            std::shared_ptr<std::FILE> mySharedFile(myFile, FileFinalizer());
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: Unable to open file" << e.what() << std::endl;
        }
    }

    {
        // Lambda that acts as a custom deleter for a std::FILE object
        auto lambdaFinalizer = [](std::FILE* myFile) -> void {
            if (myFile == nullptr)
            {
                std::cout << "File did not open" << std::endl;
            }
            else
            {
                std::fclose(myFile);
                std::cout << "File has been closed" << std::endl;
            }
        };

        // Create a file for read/write and used a stored lambda as a custom deleter to clean up resources
        try
        {
            std::FILE* myFile = std::fopen("./myFile.txt", "a+");
            std::shared_ptr<FILE> mySharedFile(myFile, lambdaFinalizer);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: Unable to open file" << e.what() << std::endl;
        }
    }

    {
        // Create a file for read/write and used a free function as a custom deleter to clean up resources
        try
        {
            std::FILE* myFile = std::fopen("./myFile.txt", "a+");
            std::shared_ptr<std::FILE> mySharedFile(myFile, functionFinalizer);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: Unable to open file" << e.what() << std::endl;
        }
    }

    {
        // Create a small loop in which records are added to the file; throw an exception at some stage
        // in the loop, catch the exception and then open the file again. Does it work?
        //
        // Response: As you'll see when running the code, we can write to a file both before and after,
        // the exception is thrown and caught. In this example, I loop 10 times. While looping, I throw
        // an exception at iteration 5. So the expected behavior is that the program will not write to
        // the file when i=5. Instead, the file should show a line for when [0-4] and [6-9].
        std::FILE* myFile = std::fopen("/Users/mlewis/CLionProjects/Baruch/Advanced-CPP-and-Modern-Design/Level 2/src/Section 2.4/Exercise 5/myFile.txt", "w+");
        std::shared_ptr<FILE> mySharedFile(myFile, FileFinalizer());
        for (int i = 0; i < 10; ++i)
        {
            try
            {
                if (i == 5)
                {
                    throw std::runtime_error("Dummy exception");
                }
                else
                {
                    if (myFile != nullptr)
                    {
                        std::string msg = "Line " + std::to_string(i) + "\n";
                        std::fwrite(msg.data(), msg.size(), 1, mySharedFile.get());
                    }
                }
            }
            catch (const std::exception& e)
            {
                // Log the error on the error stream
                std::cerr << e.what() << std::endl;
            }
        }

        std::fclose(myFile);
    }

    return 0;
}