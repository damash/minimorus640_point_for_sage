//
//  point_for_sage.h
//  sat_write_ieq
//
//  Created by 徐圣源 on 2019/10/29.
//  Copyright © 2019 徐圣源. All rights reserved.
//

#ifndef point_for_sage_h
#define point_for_sage_h
void point_for_sage(vector<vector<int>> possible_point,string file_name_for_sage)
{
    int i,j;
    string path_for_sage="/Users/xushengyuan/Desktop/sat/point_set/"+file_name_for_sage+".txt";
    ofstream outFile;
    outFile.open(path_for_sage,ios::out);
    outFile<<"myPoints = [\\"<<endl;
    for(i=0;i<possible_point.size();i++){
        outFile<<"[";
        for(j=0;j<possible_point[i].size()-1;j++){
            outFile<<possible_point[i][j]<<",";
        }
        if(i==possible_point.size()-1&&j==possible_point[i].size()-1){
            outFile<<possible_point[i][j]<<"]]"<<endl;
        }
        else{
        outFile<<possible_point[i][j]<<"] ,\\"<<endl;
    }
    }
    outFile<<"poly_test= Polyhedron(vertices= myPoints)"<<endl;
    outFile<<"for v in poly_test.inequality_generator():"<<endl;
    outFile<<"    print v"<<endl;

}

#endif /* point_for_sage_h */
