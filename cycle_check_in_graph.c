/*
 *check whether there is a cycle in graph
 */

#include <stdio.h>

#define TOTAL_NODE_NUMBER 6
char adj_matrix[6][6] = {
    1,1,1,0,0,0,
    0,1,0,0,0,1,
    0,0,1,1,0,0,
    0,0,0,1,1,0,
    0,0,0,0,1,1,
    0,0,0,0,0,1
};
char shortest_jump[6][6] = {
	-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,
}
void main() {
    int node_index = 0;
    int loop = 0；
    int dst_result[TOTAL_NODE_NUMBER] = {0},dst_result_cnt = 0, dst_jump_cnt[TOTAL_NODE_NUMBER] = 0;
    int src_result[TOTAL_NODE_NUMBER] = {0},src_result_cnt = 0; src_jump_cnt[TOTAL_NODE_NUMBER] = 0;
    int i,j,k;
    for(node_index = 0; node_index < TOTAL_NODE_NUMBER; node_index ++) {  //遍历图中每个节点
        dst_jump_cnt[0] = 1;//0跳上的节点个数，自身节点，必然为1；
        dst_result[0] = node_index;//0跳上的节点数组，只有一个即自身节点。
        src_jump_cnt[0] = 1;
        src_result[0] = node_index;
        for(loop = 1; ; loop ++){//遍历从一个节点A出发的跳数
            for(i = 0; i < dst_jump_cnt[loop-1]; i ++) {//遍历到节点A距离LOOP-1跳的节点
                for(j = 0; j < TOTAL_NODE_NUMBER; j ++) {//以到节点A距离LOOP-1跳的节点b作为起始地点查找LOOP跳的节点
                   k = dst_result[i];
				   if(k == j){//跳过自身节点
						continue;
                    }
                    if(adj_matrix[k][j] != 0) {
						if(shortest_jump[k][j] == -1) {//j节点之前尚未添加到K节点的X跳邻接点中
							shortest_jump[k][j] = loop;
							dst_jump_cnt[loop] ++;
							dst_reult[]
						}
					}
                }
            }
        }
    }
}
