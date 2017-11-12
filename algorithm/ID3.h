// Copyright (c) 2017, Pei Xingxin
// Filename:  ID3.h
// Description:
//          1. 初始化，根据当前的分类来算出整体的熵
//             entropy = -(sigma(pi*log2(pi)))
//             面对每一种选择的概率pi
//          2. 对于每一步选择，我们计算当前可能的选择Di
//            Di = -(sigma(pi*log2(pi)))
//            在Di下面对每一种选择的的概率pi
//          3. for each Di, select max(entroy - pi * Di)
//            对于di来说，发生的概率是pi
// Created:  11/12/2017 14:36:58
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

