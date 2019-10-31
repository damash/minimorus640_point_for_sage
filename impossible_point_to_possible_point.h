//
//  impossible_point_to_possible_point.h
//  sat_write_ieq
//
//  Created by 徐圣源 on 2019/10/29.
//  Copyright © 2019 徐圣源. All rights reserved.
//

#ifndef impossible_point_to_possible_point_h
#define impossible_point_to_possible_point_h
#include <vector>
using namespace std;
vector<int> convert10to2(int a,int t)       //t为比特数
{
    vector<int> c(t);
    int i=1;
    
    while(a!=0)
    {
        c[t-i]=a%2;
        a=a/2;
        i++;
    }
    return c;
}

int convert2to10(vector<int> c)
{
    int a=0,i;
    
    for(i=c.size()-1;i>=0;i--)
    {
        a+=c[i]*(pow(2.0,(c.size()-1-i)));
    }
    return a;
}

vector<vector<int>> impossible_point_to_possible_point(vector<vector<int>> a,int n)   //已知不可行点求所有可行点
{
    vector<int> tmp;    //用来储存所有可行点的10进制表示
    vector<int> tmp2;   //用来储存所有不可行点的10进制表示
    int i;
    for(i=0;i<a.size();i++){
        tmp.push_back(convert2to10(a[i]));
    }
    
    for(i=0;i<pow(2.0,n);i++){
        vector<int>::iterator it = find(tmp.begin(), tmp.end(), i);
        if (it == tmp.end())        //若不在可行点集合内
            tmp2.push_back(i);
    }
    
    vector<vector<int>> res;
    vector<int> x;
    
    for(i=0;i<tmp2.size();i++){
        x=convert10to2(tmp2[i],n);
        res.push_back(x);
    }
    return res;
}

#endif /* impossible_point_to_possible_point_h */
