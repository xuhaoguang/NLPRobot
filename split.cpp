/*
 * File Name: split.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Fri Dec 22 14:45:12 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 
*/ 

#include <iostream>
#include "stdio.h"
#include <string.h>
#include "NLPIR.h"
using namespace std;

int main(int argc, char** argv){
    if(!NLPIR_Init("", UTF8_CODE, "0")){ //the 2nd para means UTF-8 encoding 
        cout << "NLPIR ERROR" << endl;
    }
   
    int nCount; //the count of split words
    string s = "今天是中国共产党第十九次全国代表大会召开的日子，全国人民都非常开心，我爱你中国，习近平总书记发表了重要讲话，李克强总量主持会议，会议将持续5天，全国各级人民代表纷纷畅谈未来";
    //const char* pResult = NLPIR_ParagraphProcess(s.c_str());
    //cout << pResult << endl << endl;;
 
    //result_t is a struct, it contains some elems
    const result_t* pResult = NLPIR_ParagraphProcessA(s.c_str(), &nCount);
	char *sWhichDic;
	char sWord[100];

    cout << pResult << endl;
	for(int i=0; i<nCount; i++){   //print split words
		sWhichDic = "";
		switch (pResult[i].word_type){
		    case 0:
		    	sWhichDic = "核心词典";
		    	break;
		    case 1:
		    	sWhichDic = "用户词典";
		    	break;
		    case 2:
		    	sWhichDic = "专业词典";
		    	break;
		    default:
			    break;
		}
		
        strncpy(sWord, s.c_str() + pResult[i].start, pResult[i].length);
		sWord[pResult[i].length] = 0;

        cout << "No." << i << "\t"
             << "start: " << pResult[i].start << "\t"
             << "length: " << pResult[i].length << "\t"
             << "POS_ID: " << pResult[i].iPOS << "\t"
             << "Word_ID: " << pResult[i].word_ID  << "\t"
             << "UserDefine: " << sWhichDic << "\t"
             << "Word: " << sWord << "\t"
             << "Weight: " << pResult[i].weight << endl;
	}




    const char* keyword = NLPIR_GetKeyWords(s.c_str());
    cout << keyword << endl;
    NLPIR_Exit();
    return 0;
} 
