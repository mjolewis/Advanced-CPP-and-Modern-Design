//
// Created by Michael Lewis on 7/22/23.
//

#include <iostream>
#include <regex>
#include <string>

// Part A - We present a number of test cases of regular expressions and target strings.
// Which evaluate to true and which evaluate to false?
void test_characters()
{
    std::cout << "\n*** Test Digits ***" << std::endl;

    std::regex myReg("[a-z]*");
    std::regex myReg2("[a-z]+");
    std::regex myReg3("[A-Za-z\\s]+");
    std::regex myReg4("[a-zA-Z0-9]+");

    std::string s1("aza");
    std::string s2("1");
    std::string s3("b");
    std::string s4("ZZ TOP");
    std::string s5("123CPP");

    std::match_results<decltype(s1.begin())> match1;
    std::match_results<decltype(s2.begin())> match2;
    std::match_results<decltype(s3.begin())> match3;
    std::match_results<decltype(s4.begin())> match4;
    std::match_results<decltype(s5.begin())> match5;

    bool is_match_1 = std::regex_match(s1.begin(), s1.end(), match1, myReg);
    std::cout << std::boolalpha << is_match_1 << " : " << match1[0] << std::endl;
    bool is_match_2 = std::regex_match(s1.begin(), s1.end(), match1, myReg2);
    std::cout << std::boolalpha << is_match_2 << " : " << match1[0] << std::endl;
    bool is_match_3 = std::regex_match(s1.begin(), s1.end(), match1, myReg3);
    std::cout << std::boolalpha << is_match_3 << " : " << match1[0] << std::endl;
    bool is_match_4 = std::regex_match(s1.begin(), s1.end(), match1, myReg4);
    std::cout << std::boolalpha << is_match_4 << " : " << match1[0] << std::endl;

    is_match_1 = std::regex_match(s2.begin(), s2.end(), match2, myReg);
    std::cout << std::boolalpha << is_match_1 << " : " << match2[0] << std::endl;
    is_match_2 = std::regex_match(s2.begin(), s2.end(), match2, myReg2);
    std::cout << std::boolalpha << is_match_2 << " : " << match2[0] << std::endl;
    is_match_3 = std::regex_match(s2.begin(), s2.end(), match2, myReg3);
    std::cout << std::boolalpha << is_match_3 << " : " << match2[0] << std::endl;
    is_match_4 = std::regex_match(s2.begin(), s2.end(), match2, myReg4);
    std::cout << std::boolalpha << is_match_4 << " : " << match2[0] << std::endl;

    is_match_1 = std::regex_match(s3.begin(), s3.end(), match3, myReg);
    std::cout << std::boolalpha << is_match_1 << " : " << match3[0] << std::endl;
    is_match_2 = std::regex_match(s3.begin(), s3.end(), match3, myReg2);
    std::cout << std::boolalpha << is_match_2 << " : " << match3[0] << std::endl;
    is_match_3 = std::regex_match(s3.begin(), s3.end(), match3, myReg3);
    std::cout << std::boolalpha << is_match_3 << " : " << match3[0] << std::endl;
    is_match_4 = std::regex_match(s3.begin(), s3.end(), match3, myReg4);
    std::cout << std::boolalpha << is_match_4 << " : " << match3[0] << std::endl;

    is_match_1 = std::regex_match(s4.begin(), s4.end(), match4, myReg);
    std::cout << std::boolalpha << is_match_1 << " : " << match4[0] << std::endl;
    is_match_2 = std::regex_match(s4.begin(), s4.end(), match4, myReg2);
    std::cout << std::boolalpha << is_match_2 << " : " << match4[0] << std::endl;
    is_match_3 = std::regex_match(s4.begin(), s4.end(), match4, myReg3);
    std::cout << std::boolalpha << is_match_3 << " : " << match4[0] << std::endl;
    is_match_4 = std::regex_match(s4.begin(), s4.end(), match4, myReg4);
    std::cout << std::boolalpha << is_match_4 << " : " << match4[0] << std::endl;

    is_match_1 = std::regex_match(s5.begin(), s5.end(), match5, myReg);
    std::cout << std::boolalpha << is_match_1 << " : " << match5[0] << std::endl;
    is_match_2 = std::regex_match(s5.begin(), s5.end(), match5, myReg2);
    std::cout << std::boolalpha << is_match_2 << " : " << match5[0] << std::endl;
    is_match_3 = std::regex_match(s5.begin(), s5.end(), match5, myReg3);
    std::cout << std::boolalpha << is_match_3 << " : " << match5[0] << std::endl;
    is_match_4 = std::regex_match(s5.begin(), s5.end(), match5, myReg4);
    std::cout << std::boolalpha << is_match_4 << " : " << match5[0] << std::endl;
}

// Part B - Test digits
void test_digits()
{
    std::cout << "\n*** Test Digits ***" << std::endl;

    std::regex myNumericReg("\\d{2}");

    std::string f("34");
    std::match_results<decltype(f.begin())> match1;
    bool is_match_1 = std::regex_match(f.begin(), f.end(), match1, myNumericReg);
    std::cout << std::boolalpha << is_match_1 << " : " << match1[0] << std::endl;

    std::string s("345");
    std::match_results<decltype(s.begin())> match2;
    bool is_match_2 = std::regex_match(s.begin(), s.end(), match2, myNumericReg);
    std::cout << std::boolalpha << is_match_2 << " : " << match2[0] << std::endl;

    std::string s1("345a");
    std::match_results<decltype(s1.begin())> match3;
    bool is_match_3 = std::regex_match(s1.begin(), s1.end(), match3, myNumericReg);
    std::cout << std::boolalpha << is_match_3 << " : " << match3[0] << std::endl;

    std::string s2("ba");
    std::match_results<decltype(s2.begin())> match4;
    bool is_match_4 = std::regex_match(s2.begin(), s2.end(), match4, myNumericReg);
    std::cout << std::boolalpha << is_match_4 << " : " << match4[0] << std::endl;
}

// Part C - Test alternatives using OR
void test_alternatives()
{
    std::cout << "\n*** Test Alternatives ***" << std::endl;
    std::regex myAltReg("(new)|(delete)");

    std::string s4A("new");
    std::match_results<decltype(s4A.begin())> match1;
    bool is_match_1 = std::regex_match(s4A.begin(), s4A.end(), match1, myAltReg);
    std::cout << std::boolalpha << is_match_1 << " : " << match1[0] << std::endl;

    std::string s5("delete");
    std::match_results<decltype(s5.begin())> match2;
    bool is_match_2 = std::regex_match(s5.begin(), s5.end(), match2, myAltReg);
    std::cout << std::boolalpha << is_match_2 << " : " << match2[0] << std::endl;

    std::string s6("malloc");
    std::match_results<decltype(s6.begin())> match3;
    bool is_match_3 = std::regex_match(s6.begin(), s6.end(), match3, myAltReg);
    std::cout << std::boolalpha << is_match_3 << " : " << match3[0] << std::endl;

    std::string s7("newdelete");
    std::match_results<decltype(s7.begin())> match4;
    bool is_match_4 = std::regex_match(s7.begin(), s7.end(), match4, myAltReg);
    std::cout << std::boolalpha << is_match_4 << " : " << match4[0] << std::endl;
}

// Part D - Test Kleene Start syntax
void test_kleene_star()
{
    std::cout << "\n*** Test Kleene Star ***" << std::endl;

    std::regex myReg3("A*");
    std::string testA("1");
    std::match_results<decltype(testA.begin())> aMatch;
    bool is_match = std::regex_match(testA.begin(), testA.end(), aMatch, myReg3);
    std::cout << std::boolalpha << is_match << " : " << aMatch[0] << std::endl;

    std::string testAStar("AAAAAAAAAAAAAAAAAA");
    std::match_results<decltype(testAStar.begin())> aStarMatch;
    bool is_match_1 = std::regex_match(testAStar.begin(), testAStar.end(), aStarMatch, myReg3);
    std::cout << std::boolalpha << is_match_1 << " : " << aStarMatch[0] << std::endl;

    std::regex myReg4("A+");
    std::string testAPlus("A");
    std::match_results<decltype(testAPlus.begin())> aPlusMatch;
    bool is_match_2 = std::regex_match(testAPlus.begin(), testAPlus.end(), aPlusMatch, myReg4);
    std::cout << std::boolalpha << is_match_2 << " : " << aPlusMatch[0] << std::endl;

    std::regex myReg5("(\\d{2})");
    std::string testTwoDigit("12");
    std::match_results<decltype(testTwoDigit.begin())> twoDigitMatch;
    bool is_match_3 = std::regex_match(testTwoDigit.begin(), testTwoDigit.end(), twoDigitMatch, myReg5);
    std::cout << std::boolalpha << is_match_3 << " : " << twoDigitMatch[0] << std::endl;

    //Note - This regex was commented out in the HW. It is incorrect.
    // The space in from of the 4 is invalid. See the uncommented out version directly below it
    //regex myReg6("\\d{2, 4}");

    std::regex myReg6("(\\d{2,4})");
    std::string testFourDigit("1234");
    std::match_results<decltype(testFourDigit.begin())> fourDigitMatch;
    bool is_match_5 = std::regex_match(testFourDigit.begin(), testFourDigit.end(), fourDigitMatch, myReg6);
    std::cout << std::boolalpha << is_match_5 << " : " << fourDigitMatch[0] << std::endl;

    std::regex myReg7("\\d{1,}");
    std::string testOneDigit("12345437203208434243423");
    std::match_results<decltype(testOneDigit.begin())> oneDigitMatch;
    bool is_match_7 = std::regex_match(testOneDigit.begin(), testOneDigit.end(), oneDigitMatch, myReg7);
    std::cout << std::boolalpha << is_match_7 << " : " << oneDigitMatch[0] << std::endl;

    std::regex myReg8("(A*B*)*");
    std::string testAStarBStar("ABBBBAAAABAAAABBBBBAAAB");
    std::match_results<decltype(testAStarBStar.begin())> aStarBStarMatch;
    bool is_match_8 = std::regex_match(testAStarBStar.begin(), testAStarBStar.end(), aStarBStarMatch, myReg8);
    std::cout << std::boolalpha << is_match_8 << " : " << aStarBStarMatch[0] << std::endl;
}

// Part E - Test alphanumeric characters
void test_alphanumeric()
{
    std::cout << "\n*** Test Alphanumeric ***" << std::endl;

    std::regex rC("(\\w)*"); // Alphanumeric (word) A-Za-z0-9
    std::string sC("abcABC123XZZ");
    std::match_results<decltype(sC.begin())> sCMatch;
    bool is_match = std::regex_match(sC.begin(), sC.end(), sCMatch, rC);
    std::cout << std::boolalpha << is_match << " : " << sCMatch[0] << std::endl;

    std::regex rC1("(\\W)*"); // Not a word
    std::string sC1("abc");
    std::match_results<decltype(sC1.begin())> sC1Match;
    bool is_match_1 = std::regex_match(sC1.begin(), sC1.end(), sC1Match, rC1);
    std::cout << std::boolalpha << is_match_1 << " : " << sC1Match[0] << std::endl;

    std::regex rC2("[A-Za-z0-9_]*"); // Alphanumeric (word) A-Za-z0-9
    std::string sC2("A12678Z909za");
    std::match_results<decltype(sC2.begin())> sC2Match;
    bool is_match_2 = std::regex_match(sC2.begin(), sC2.end(), sC2Match, rC2);
    std::cout << std::boolalpha << is_match_2 << " : " << sC2Match[0] << std::endl;

    std::regex rC3("(\\bWHOLEWORD)"); // Matches whole word
    std::string sC3("WHOLEWORD");
    std::match_results<decltype(sC3.begin())> sC3Match;
    bool is_match_3 = std::regex_match(sC3.begin(), sC3.end(), sC3Match, rC3);
    std::cout << std::boolalpha << is_match_3 << " : " << sC3Match[0] << std::endl;
}

// Additional tests to illustrate different regular expressions behave
void test_ecma_posix()
{
    std::cout << "\n*** Test Ecma vs Posix ***" << std::endl;

    std::string str = "zzxayyzz";

    std::regex re1(".*(a|xayy)"); // ECMA
    std::match_results<decltype(str.begin())> match1;
    bool is_match = std::regex_search(str.begin(), str.end(), match1, re1);
    std::cout << is_match << " : " << match1[0] << std::endl;

    std::regex re2(".*(a|xayy)", std::regex::basic); // POSIX
    std::match_results<decltype(str.begin())> match2;
    bool is_match_2 = std::regex_search(str.begin(), str.end(), match2, re2);
    std::cout << is_match_2 << " : " << match2[0] << std::endl;
}

int main()
{
    test_characters();
    test_digits();
    test_alternatives();
    test_kleene_star();
    test_alphanumeric();
    test_ecma_posix();
    return 0;
}