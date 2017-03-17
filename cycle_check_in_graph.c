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

/*shortest_path[i][j].node_set表示从i到j的路径包含到节点，含i，j
 *shortest_path[i][j].node_cnt表示从i到j到路径包含的节点个数，含i，j*/
typedef struct stPath {
	char node_cnt;
	char node_set[TOTAL_NODE_NUMBER];
};
stPath shortest_path[TOTAL_NODE_NUMBER][TOTAL_NODE_NUMBER];

void add_to_shortest_path(char firstnode, char lastnode, char newnode) {
	char tmp_cnt, i, tmp_node;
	
	tmp_cnt = shortest_path[firstnode][lastnode].node_cnt;
	for(i = 0; i < tmp_cnt, i++) {
	    shortest_path[firstnode][newnode].node_set[i] = shortest_path[firstnode][lastnode].node_set[i];
	}
    shortest_path[firstnode][newnode].node_set[i] = newnode;
	shortest_path[firstnode][newnode].node_cnt = i + 1;
}

void graph_init() {
	int node_index;
	memset(nodeset_dst, -1, sizeof(nodeset_dst));
	memset(nodeset_dst_cnt, 0, sizeof(nodeset_dst_cnt));
	memset(nodeset_dst_map, 0, sizeof(nodeset_dst_map));

    memset(nodeset_src, -1, sizeof(nodeset_src));
	memset(nodeset_src_cnt, 0, sizeof(nodeset_src_cnt));
	memset(nodeset_src_map, 0, sizeof(nodeset_src_map));

	memset(shortest_path, -1, sizeof(shortest_path));

	for(node_index = 0; node_index < TOTAL_NODE_NUMBER; node_index ++) {
        nodeset_dst[node_index][0][0] = node_index;
		nodeset_dst_cnt[node_index][0] = 1;
		nodeset_dst_map[node_index][node_index] = 1;
	
		nodeset_src[node_index][0][0] = node_index;
		nodeset_src_cnt[node_index][0] = 1;
		nodeset_src_map[node_index][node_index] = 1;
	}
}

void main() {
    graph_init();
	int node_index, loop, i, j;
	int last_node;

	/*定义成函数find_node(start_node,flag),flag为0表示查找从start_node可达的节点，flag为1表示查找可到达start_node的节点*/
	for(node_index = 0; node_index < TOTAL_NODE_NUMBER; node_index ++) {  //遍历图中每个节点
   		for(loop = 1; nodeset_dst_cnt[node_index][loop] != 0;loop ++){//遍历从一个节点A出发的跳数
            for(i = 0; i < nodeset_dst_cnt[node_index][loop-1]; i ++) {//遍历到节点A距离LOOP-1跳的节点
				last_node = nodeset_dst[node_index][loop -1][i];
                for(j = 0; j < TOTAL_NODE_NUMBER; j ++) {//以到节点A距离LOOP-1跳的节点b作为起始地点查找LOOP跳的节点
					if(last_node == j || nodeset_dst_map[node_index][j] != 0){
						continue;
					} else if(adj_matrix[last_node][j] != 0) {//将节点j加入到node_index的loop跳可达节点中
						add_to_shortest_path(node_index, last_node, j);
						
						node_cnt = nodeset_dst_cnt[node_index][loop];
						nodeset_dst[node_index][loop][node_cnt] = j;
						nodeset_dst_cnt[node_index][loop] ++;

						nodeset_dst_map[node_index][j] = nodeset_src_map[j][node_index] = 1;

						if(nodeset_src_map[nose_index][j] != 0){
						//找到环了
						}
					}
                }
            }
        }
        
    }
}
