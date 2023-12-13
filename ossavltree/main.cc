/*
BSD-3-Clause
Copyright (c) 2023, Jihwan Kim
All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 
* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
* Neither the name of the <organization> nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL Jihwan Kim Yun BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

작성자 : 김지환
작성일 : 2023년 12월 13일
*/
#include <iostream>
#include "set.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--)
    {
        int t2;
        cin >> t2;
        Int_AVLtree_set set;
        string s;
        while (t2--)
        {
            cin >> s;
            int tmp;
            if (s == "insert")
            {
                cin >> tmp;
                set.Insert(tmp);
            }
            else if (s == "find")
            {
                cin >> tmp;
                set.Find(tmp);
            }
            else if (s == "minimum")
            {
                cin >> tmp;
                set.Minimum(tmp);
            }
            else if (s == "maximum")
            {
                cin >> tmp;
                set.Maximum(tmp);
            }
            else if (s == "empty")
            {
                set.Empty();
            }
            else if (s == "size")
            {
                set.Size();
            }
            else if (s == "rank")
            {
                cin >> tmp;
                set.Rank(tmp);
            }
            else if (s == "erase")
            {
                cin >> tmp;
                set.Erase(tmp);
            }
        }
    }
}