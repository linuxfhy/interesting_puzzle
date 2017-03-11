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
char nodeset_dst_map[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER];

char nodeset_src[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER];
char nodeset_src_cnt[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER-1];
char nodeset_src_map[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER];

char shortest_path[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER];
void add_to_shortest_path(char firstnode, char lastnode, char newnode) {
	char tmp_cnt = 0;
	for(tmp_cnt = 0; ;tmp_cnt ++) {
		if(shortest_path[firstnode][lastnode][tmp_cnt] != -1) {
			shortest_path[firstnode][newnode][tmp_cnt] = shortest_path[firstnode][lastnode][tmp_cnt];
			continue;
		}
		break;
	}
	shortest_path[firstnode][newnode][tmp_cnt] = newnode;
}

void main() {
    memset(nodeset_dst, -1, sizeof(nodeset_dst));
	memset(nodeset_dst_cnt, 0, sizeof(nodeset_dst_cnt));
	memset(nodeset_dst_map, 0, sizeof(nodeset_dst_map));

    memset(nodeset_src, -1, sizeof(nodeset_src));
	memset(nodeset_src_cnt, 0, sizeof(nodeset_src_cnt));
	memset(nodeset_src_map, 0, sizeof(nodeset_src_map));
	
	memset(shortest_path, -1, sizeof(shortest_path));
    /*定义成函数find_node(start_node,flag),flag为0表示查找从start_node可达的节点，flag为1表示查找可到达start_node的节点*/
	for(node_index = 0; node_index < TOTAL_NODE_NUMBER; node_index ++) {  //遍历图中每个节点
        nodeset_dst[node_index][0][0] = node_index;
		nodeset_dst_cnt[node_index][0] = 1;
		nodeset_dst_map[node_index][node_index] = 1;
	
		nodeset_src[node_index][0][0] = node_index;
		nodeset_src_cnt[node_index][0] = 1;
		nodeset_src_map[node_index][node_index] = 1;

		for(loop = 1; ;loop ++){//遍历从一个节点A出发的跳数
            for(i = 0; i < nodeset_dst_cnt[loop-1]; i ++) {//遍历到节点A距离LOOP-1跳的节点
				node_src_tmp = nodeset_dst[node_index][loop -1][i];
                for(j = 0; j < TOTAL_NODE_NUMBER; j ++) {//以到节点A距离LOOP-1跳的节点b作为起始地点查找LOOP跳的节点
					if(node_src_tmp == j)
						continue;
                    if(adj_matrix[node_src_tmp][j] != 0) {//将节点j加入到node_index的loop跳可达节点中
						tmp_cnt = nodeset_dst_cnt[node_index][loop];
						nodeset_dst[node_index][loop][tmp_cnt] = j;
						nodeset_dst_cnt[node_index][loop] ++;
						nodeset_dst_map[node_index][j] = 1;
						/*todo:添加一个节点时，增加处理shortest_path数组的代码*/
						add_to_shortest_path(node_index, node_src_tmp, j);
					}
                }
            }
        }
        
    }
}
