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
#include "set.h"

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--)
    {
        int t2;
        std::cin >> t2;
        Int_AVLtree_set set;
        std::string s;
        while (t2--)
        {
            std::cin >> s;
            int tmp;
            if (s == "insert")
            {
                std::cin >> tmp;
                std::cout << set.Insert(tmp) << "\n";
            }
            else if (s == "find")
            {
                std::cin >> tmp;
                std::cout << set.Find(tmp) << "\n";
            }
            else if (s == "minimum")
            {
                std::cin >> tmp;
                std::pair<int, int> p = set.Minimum(tmp);
                std::cout << p.first << " " << p.second << "\n";
            }
            else if (s == "maximum")
            {
                std::cin >> tmp;
                std::pair<int, int> p = set.Maximum(tmp);
                std::cout << p.first << " " << p.second << "\n";
            }
            else if (s == "empty")
            {
                std::cout << set.Empty() << "\n";
            }
            else if (s == "size")
            {
                std::cout << set.Size() << "\n";
            }
            else if (s == "rank")
            {
                std::cin >> tmp;
                std::pair<int, int> p = set.Rank(tmp);
                if (p.first == -1)
                    std::cout << 0 << "\n";
                else
                    std::cout << p.first << " " << p.second << "\n";
            }
            else if (s == "erase")
            {
                std::cin >> tmp;
                std::cout << set.Erase(tmp) << "\n";
            }
        }
    }
}