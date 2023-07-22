//
// Illustrate how to process data in an ASCII file in CSV format.
//
// Created by Michael Lewis on 7/22/23.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <tuple>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>

using Data = std::tuple<boost::gregorian::date, std::vector<double>>;
using ResultSet = std::list<Data>;

// Pre-process the string. Use STL and Boost as appropriate. Note - Can use boost::trim; however,
// that requires trimming the beginning, end, and remaining spaces, so requires more code
void pre_process(std::string& s)
{
    // Discard return value since s is a reference
    std::remove(s.begin(), s.end(), ' ');
}

// Utility function that converts a string into a date
template<typename Date>
Date create_date(const std::string& yyyy, const std::string& mm, const std::string& d)
{
    int year = boost::lexical_cast<int>(yyyy);
    int month = boost::lexical_cast<int>(mm);
    int day = boost::lexical_cast<int>(d);

    return {year, month, day};
}

// Utility function that re-packages time-series data
template<typename T>
std::vector<T> create_prices_container(const std::vector<std::string>& prices, int startIdx)
{
    std::vector<T> price_container;

    for (size_t i = startIdx; i < prices.size(); ++i)
    {
        // Use at() instead of [] to perform bounds checking
        price_container.push_back(boost::lexical_cast<T>(prices.at(i)));
    }

    return price_container;
}

// Process the data in an ASCII file in CSV format.
template<typename Date, typename T>
ResultSet read_file(const char* file_name)
{
    std::vector<std::string> split_row;
    std::string line;
    ResultSet time_series;
    Data row;

    try
    {
        // Open the file
        std::ifstream input(file_name);

        if (!input)
        {
            std::cerr << "Unable to open file" << std::endl;
            return {}; // Return empty result set
        }

        // Discard header row
        getline(input, line);

        // Process all other rows in the dataset
        while (getline(input, line))
        {
            pre_process(line);

            if (!line.empty())
            {
                boost::split(split_row, line, boost::is_any_of(",-"));

                // Construct the date and tuple of time series data
                auto date = create_date<Date>(split_row[0], split_row[1], split_row[2]);
                row = std::make_tuple(date, create_prices_container<T>(split_row, 3));
                time_series.push_back(row);
            }
        }
    } // file is closed automatically when it goes out of scope
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return time_series;
}

// Log the data to console to verify results
void print(const ResultSet& resultSet)
{
    for (const auto& result : resultSet)
    {
        boost::gregorian::date date;
        std::vector<double> data;
        double open, high, low, close, volume, adj_close;
        std::tie(date, data) = result;

        open = data.at(0);
        high = data.at(1);
        low = data.at(2);
        close = data.at(3);
        volume = data.at(4);
        adj_close = data.at(5);
        std::cout << date << "*"
                << "," << open
                << "," << high
                << "," << low
                << "," << close
                << "," << volume
                << "," << adj_close
                << "," << std::endl;
    }
}

int main()
{
    const char* file = "/Users/mlewis/CLionProjects/Baruch/Advanced-CPP-and-Modern-Design/Level 5/src/Section 5.1/Exercise 4/time_series.csv";

    try
    {
        ResultSet resultSet = read_file<boost::gregorian::date, double>(file);
        print(resultSet);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}