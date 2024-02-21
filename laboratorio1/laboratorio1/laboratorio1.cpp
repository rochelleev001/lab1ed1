
#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <json/value.h>
#include <json/json.h>
#include <vector>
#include <unordered_map>

using json = nlohmann::json;
using namespace std;

int main()
{
    ofstream outputfile("output.txt");
    ifstream inputfile("C:/input_example.jsonl");
    if (!inputfile.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    if (!outputfile.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string line;
    while (getline(inputfile, line)) {
        try {
            // Intenta analizar la línea del archivo json
            json j = json::parse(line);


            if (j.contains("input1") && j.contains("input2")) {

                //  cout << "Entrada 1: " << j["input1"] << endl;
                  //cout << "Entrada 2: " << j["input2"] << endl;
                  //map
                string map = j["input1"];
                // requirements
                string requirements = j["input2"];
                {
                    vector<unordered_map<string, bool>> map = j["input1"];
                    vector<string> requirements = j["input2"];
                    vector<int> recommended_appartments;
                    unordered_map<string, bool> h0;
                    unordered_map<string, bool> h1;
                    unordered_map<string, bool> h2;
                    unordered_map<string, bool> h3;
                    unordered_map<string, bool> h4;
                    unordered_map<string, bool> h5;
                    unordered_map<string, bool> h6;
                    unordered_map<string, bool> h7;
                    unordered_map<string, bool> h8;
                    unordered_map<string, bool> h9;
                    int i = 0;
                    for (size_t i = 0; i < map.size(); ++i) 
                    {
                        bool required = true;
                        for (const string& request : requirements) {
                            if (map[i].find(request) == map[i].end()) {

                                std::vector<bool> bools = { true, false };
                                std::vector<int> values(bools.size());
                                required = false;
                                break;
                                for (size_t i = 0; i < bools.size(); ++i) {
                                    values[i] = bools[i] ? 1 : 0;
                                }

                                for (size_t i = 0; i < values.size(); ++i) {
                                    std::cout << "Value " << i + 1 << ": " << values[i] << std::endl;
                                }
                                    
                                h0["Pharmacy, Beauty Salon, Mall, Academy"] = false;
                                h0["Restaurant, Vet, Hospital, Clinic, Gas Station"] = true;
                                h0["Beauty Salon"] = false;
                                h1["gym"] = true;
                                h2["Academy, School"] = true;
                                h3["Academy"] = true;
                                h4["Academy, Store"] = true;
                                h5["Academy, Store"] = true;
                                h6["Academy, Store"] = true;
                                h7["Academy, Store"] = true;
                                h8["Academy, Store"] = true;
                                h9["Academy, Store"] = true;

                                i++;
                            }
                        }
                    if (required) {
                        recommended_appartments.push_back(i);
                        map.push_back(h0);
                        map.push_back(h1);
                        map.push_back(h2);
                        map.push_back(h3);
                        map.push_back(h4);
                        map.push_back(h5);
                        map.push_back(h6);
                        map.push_back(h7);
                        map.push_back(h8);
                        map.push_back(h9);
                    }
                }
                    outputfile << "[";
                    for (size_t i = 0; i < recommended_appartments.size(); ++i) {
                        outputfile << recommended_appartments[i];
                        if (i < recommended_appartments.size() - 1) {
                            outputfile << ", ";
                        }
                    }
                    outputfile << "]" << endl;

                    
                }
                
            }
            else {
                cerr << "La línea no contiene las claves necesarias." << endl;
            }
        }
        catch (json::parse_error& e) {
            cerr << "Error al analizar JSON en la línea: " << e.what() << endl;
            
        }
    }
    inputfile.close();
    outputfile.close();
    return 0;
}
