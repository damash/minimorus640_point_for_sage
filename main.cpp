//
//  main.cpp
//  sat_write_ieq
//
//  Created by 徐圣源 on 2019/10/29.
//  Copyright © 2019 徐圣源. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include "impossible_point_to_possible_point.h"
#include "point_for_sage.h"
using namespace std;
int main() {
    vector<vector<int>> impossible_point;
    string file_name_for_impossible_point="impossible_point_for_s_1_1";
    string impossible_point_file="/Users/xushengyuan/Desktop/sat/point_set/"+file_name_for_impossible_point+".txt";
    
    ifstream in(impossible_point_file);
    int i=0,j;
    char t;
    vector<int> tmp;
    // 有该文件
    if(in){
        while (in>>t){
            if((int)t>=48&&(int)t<=57){
                tmp.push_back(t-48);
                if(++i%6==0){
                    impossible_point.push_back(tmp);
                    tmp.clear();
                }
            }
        }
    }
    // 没有该文件
    else {
        cout <<"no impossible point file found" << endl;
    }
    vector<vector<int>> possible_point=impossible_point_to_possible_point(impossible_point,6);
    string file_name_for_sage="possible_point_for_s_1_1_for_sage";
    point_for_sage(possible_point,file_name_for_sage);
    
    return 0;
}
