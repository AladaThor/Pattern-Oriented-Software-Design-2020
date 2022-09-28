#include <gtest/gtest.h>
#include "../src/node_scanner.h"

//%16


TEST(Scanner, word_function_test){
    string input = "facebook (30.32)";
    NodeScanner* scn = new NodeScanner(input);

    ASSERT_EQ("chrome", scn->isWord(" chrome"));
    ASSERT_EQ("chrome", scn->isWord("chrome "));
    ASSERT_EQ("chrome", scn->isWord("@&*chrome"));
    ASSERT_EQ("chrome", scn->isWord("chrome@#$"));
    ASSERT_EQ("chrome", scn->isWord("@ chrome"));
    ASSERT_EQ("chrome", scn->isWord("chrome @#$"));
    ASSERT_EQ("chrome", scn->isWord("@ &*chrome@# @#$"));
}

TEST(Scanner, Digit_function_test){
    string input = "facebook (30.32)";
    NodeScanner* scn = new NodeScanner(input);
    //cout << "Digit: " << scn->isDigit("30.32") << endl;
    ASSERT_EQ("30.32", scn->isDigit(" 30.32"));
    ASSERT_EQ("30.32", scn->isDigit("30.32 "));
    ASSERT_EQ("30.32", scn->isDigit("!@#30.32"));
    ASSERT_EQ("30.32", scn->isDigit("30.32@#$"));
    ASSERT_EQ("30.32", scn->isDigit("!@# 30.32"));
    ASSERT_EQ("30.32", scn->isDigit("30.32 @#$"));
    ASSERT_EQ("30.32", scn->isDigit("!@# 30.32DFSZ @#$"));
    ASSERT_EQ("", scn->isDigit("!@# 3.0.32DFSZ @#$"));
}
//%2
TEST(Scanner, single_app) {
    std::string input = "facebook (30.32)";
    NodeScanner* scn = new NodeScanner(input);
    //cout <<"1."<<scn->nextToken()<<endl;
    //cout <<"2."<<scn->nextToken()<<endl;
    //cout <<"3."<<scn->nextToken()<<endl;
    //cout <<"4."<<scn->nextToken()<<endl;
    ASSERT_EQ("facebook", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("30.32", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());
}

//%2
TEST(Scanner, single_folder) {
    std::string input = "favorite {}";
    NodeScanner* scn = new NodeScanner(input);

    ASSERT_EQ("favorite", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
}

//%2
TEST(Scanner, folder_contain_apps) {
    std::string input = "favorite {chrome (50.15), facebook (30.32), instagram (20.21)}";
    NodeScanner* scn = new NodeScanner(input);

    //for(int i = 0; i < 16; ++i)
    //  cout <<i <<": "<<scn->nextToken() <<endl;

    ASSERT_EQ("favorite", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("chrome", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("50.15", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("facebook", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("30.32", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("instagram", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("20.21", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());
}

//%2
TEST(Scanner, folder_contain_folders) {
    std::string input = "favorite {community {trash {}}, common {}}";
    NodeScanner* scn = new NodeScanner(input);

    ASSERT_EQ("favorite", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("community", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("trash", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("common", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
}


//%2
TEST(Scanner, tree_structure) {
    std::string input = "favorite {chrome (50.15), facebook (30.32), common {instagram (20.21), community {ubereat(40.34), line(60.66), trash{}}, youtube (70.07)}}";
    NodeScanner* scn = new NodeScanner(input);

    ASSERT_EQ("favorite", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("chrome", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("50.15", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("facebook", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("30.32", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("common", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("instagram", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("20.21", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("community", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("ubereat", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("40.34", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("line", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("60.66", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("trash", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());

    ASSERT_EQ("}", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("youtube", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("70.07", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
}

//%2
TEST(Scanner, next_token_exception) {
    std::string input = "!@#$%^&*";
    NodeScanner* scn = new NodeScanner(input);

    try {
        scn->nextToken();
        FAIL();
    }catch(std::string s) {
        ASSERT_EQ("next token doesn't exist.", s);
    }
}

//%2
TEST(Scanner, folder_contain_folders_with_ignore_symbol) {
    std::string input = "favorite !@#{$%community <>{?trash [{]}[]}, *common {+}+}";
    NodeScanner* scn = new NodeScanner(input);
    /*cout<<" 1. "<<scn->nextToken()<<endl;
    cout<<" 2. "<<scn->nextToken()<<endl;
    cout<<" 3. "<<scn->nextToken()<<endl;
    cout<<" 4. "<<scn->nextToken()<<endl;
    cout<<" 5. "<<scn->nextToken()<<endl;
    cout<<" 6. "<<scn->nextToken()<<endl;
    cout<<" 7. "<<scn->nextToken()<<endl;
    cout<<" 8. "<<scn->nextToken()<<endl;
    cout<<" 9. "<<scn->nextToken()<<endl;
    cout<<"10. "<<scn->nextToken()<<endl;
    cout<<"11. "<<scn->nextToken()<<endl;
    cout<<"12. "<<scn->nextToken()<<endl;
    cout<<"13. "<<scn->nextToken()<<endl;*/

    ASSERT_EQ("favorite", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("community", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("trash", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("common", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
}

//%2
TEST(Scanner, tree_structure_with_ignore_symbol) {
    std::string input = "~!@favorite {chrome (50.15), facebook (30.32), common#$% {instagram (20.21), community {ubereat (^&40.34)*, line (60.66][), trash {*}}, youtube (+70.07)<>}}";
    NodeScanner* scn = new NodeScanner(input);

    ASSERT_EQ("favorite", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("chrome", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("50.15", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("facebook", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("30.32", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("common", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("instagram", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("20.21", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("community", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("ubereat", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("40.34", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("line", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("60.66", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("trash", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());

    ASSERT_EQ("}", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("youtube", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("70.07", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
    ASSERT_EQ("}", scn->nextToken());
}
