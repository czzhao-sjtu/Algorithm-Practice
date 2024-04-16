import numpy as np

# 邻接矩阵：数值表示边的权重，inf表示两个结点间不存在边

def kruskal(graph):
    # graph邻接矩阵的形式
    
    #1. 从邻接矩阵中提取顶点集合, 边集
    vertexs = list(range(len(graph)))
    edges = []
    for i in range(graph.shape[0]):
        for j in range(graph.shape[1]):
            if j <= i:
                # 无向有权图的邻接矩阵是对称的
                # 保证每条可能的边只被遍历一次
                continue

            if graph[i, j] == np.inf:
                # 边的权重为np.inf表示两点之间不存在一条边
                continue 

            edges.append((i, j, graph[i, j])) # 每个边表示成(u, v, w(u, v))的三元组

    #2. 初始化空的顶点集合，边集，辅助列表(记录每个顶点属于的集合)
    new_vertexs = set()
    new_edges = []
    aux_list = list(range(len(vertexs)))

    #3. 对边集按照权重升序排序
    edges.sort(key=lambda x: x[2])

    #4. 循环
    for edge in edges:
        u, v, w_uv = edge
        if (aux_list[u] != aux_list[v]):
            # 添加u, v到顶点集合中
            new_vertexs.update({u, v})
            #添加边到边集合中
            new_edges.append(edge)
            
            #更新所有的原先属于axu_list[v]的顶点的标记
            new_aux_label = aux_list[u]
            old_aux_label = aux_list[v]
            for idx in range(len(aux_list)):
                if aux_list[idx] == old_aux_label:
                    aux_list[idx] = new_aux_label
    
    #5. 返回结果
    return new_edges

def main():
    #邻接矩阵的缩写
    matrix = np.full((7, 7), fill_value=np.inf)
    matrix[0, 1] = 7
    matrix[0, 3] = 5
    matrix[1, 2] = 8
    matrix[1, 3] = 9
    matrix[1, 4] = 7
    matrix[2, 4] = 5
    matrix[3, 4] = 15
    matrix[3, 5] = 6
    matrix[4, 5] = 8
    matrix[4, 6] = 9
    matrix[5, 6] = 11

    print(kruskal(matrix))

if __name__ == "__main__":
    main()