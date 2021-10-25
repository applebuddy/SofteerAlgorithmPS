//
//  8단변속기_Lv2_408.cpp
//  SofteerAlgorithmPS
//
//  Created by MinKyeongTae on 2021/10/26.
//

#if 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int G[8] = {0, };
    int len = 8, prev = -1;
    int diff = -1;
    bool isMixed=false;
    for(int i=0; i<len; i++) cin>>G[i];
    for(int i=0; i<len; i++) {
        if(prev != -1) {
            if(diff==-1) {
                diff = G[i]-prev;
                prev = G[i];
                continue;
            }
            
            if(diff!=G[i]-prev) {
                isMixed=true;
                break;
            }
        }
        prev = G[i];
    }
    
    printf("%s", isMixed==true ? "mixed" : (diff==1 ? "ascending" : "descending"));
}

#endif
