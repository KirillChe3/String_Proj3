#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void replace_delimeters_by_space(string& text, string delimeters, char delim)
{
    std::size_t position = text.find_first_of(delimeters.c_str());
    while (position!=std::string::npos)
    {
        if( text[position]!=delim ) text[position] = delim;
        position = text.find_first_of ( delimeters.c_str(),position+1 );
    }
    stringstream ss(text);
    text.clear();
    string word;
    while ( ss >> word )
    text += word + delim;
}

vector<string> split(string& text, char delim)
{
    vector<string> vs;
    string word;
    stringstream ss(text);
    while (ss>>word) vs.insert(vs.end(), word);
    return vs;
}

int main(int argc, char* argv[])
{
    string string_from_file;
    cout << "Input substring...";
    string string_console;
    cin >> string_console;
    ifstream file_txt;
    file_txt.open("my_text3.txt", ios::in);

    while (!file_txt.eof())
{
getline(file_txt, string_from_file);
const char * delimeters=",.!? \n\t-"; //разделители
replace_delimeters_by_space(string_from_file, delimeters, ' ');
vector<string> vector_of_strings=split(string_from_file, ' ');
for (size_t i=0; i<vector_of_strings.size(); ++i)
    {
        const auto &substring_from_file = vector_of_strings[i];
        for(size_t j =0; j<substring_from_file.length(); ++j)
            {
                if (((substring_from_file[j]-'0')>=0 && (substring_from_file[j]-'0')<=9) && substring_from_file.length() == string_console.length())//cout << str1 << i << endl;
                        {
                            vector_of_strings[i]=string_console;
                        }
            }
    }
for(auto m : vector_of_strings) cout << m << ' ';
}
file_txt.close();
cin.get();
return 0;
}
