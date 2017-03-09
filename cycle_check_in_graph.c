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


/*nodeset_dst[i][k][]表示i节点经过K跳可达节点集合
 *nodeset_dst_cnt[i][k]记录节点i从发经过k跳可达节点的个数
 *nodeset_dst_map[i][j] == 1;表示节点j在节点i的可达目的节点集合中。
 *nodeset_src[i][k][]表示经过经过k跳可达节点i的节点集合
 *nodeset_src_cnt[i][k]记录经过k跳可达节点i的节点个数
 *nodeset_src_map[i][j] == 1;表示节点j在可达节点i的源节点集合中
 *shortest_path[i][j][]记录从i到j经过的最短路径
 */
char nodeset_dst[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER];
char nodeset_dst_cnt[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER-1];
char nodeset_src[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER];
char nodeset_src_cnt[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER-1];
char shortest_path[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER];

void main() {
    int node_index = 0;
    int loop = 0；
    int dst_result[TOTAL_NODE_NUMBER] = {0},dst_result_cnt = 0, dst_jump_cnt[TOTAL_NODE_NUMBER] = 0;
    int src_result[TOTAL_NODE_NUMBER] = {0},src_result_cnt = 0; src_jump_cnt[TOTAL_NODE_NUMBER] = 0;
    
    for(node_index = 0; node_index < TOTAL_NODE_NUMBER; node_index ++) {  //遍历图中每个节点
        dst_jump_cnt[0] = 1;
        dst_result[0] = node_index;
        src_jump_cnt[0] = 1;
        src_result[0] = node_index;
        for(loop = 1; ; loop ++){//遍历从一个节点A出发的跳数
            for(i = 0; i < dst_jump_cnt[loop-1]; i ++) {//遍历到节点A距离LOOP-1跳的节点
                for(j = 0; j < TOTAL_NODE_NUMBER; j ++) {//以到节点A距离LOOP-1跳的节点b作为起始地点查找LOOP跳的节点
                    if(adj_matrix[dst_result[i] == j)
                                  continue;
                    if(adj_matrix[dst_result[i]][j] != 0)
                }
            }
        }
        
    }
}