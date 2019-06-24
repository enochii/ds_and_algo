# 19/5/27

MAX_DIS = 1000000

def floyd_warshall(ori_mat):
    """
    input: direct distance of all vertices

    output: the shortest distance of all vertices
    """

    # init
    n = len(ori_mat)
    prev = ori_mat
    next = [[0]*n for i in range(n)]
    
    path = [[None]*n for i in range(n)]
    next_path = [[None]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            path[i][j] = i if i!=j and prev[i][j]<MAX_DIS else None



    # 
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if prev[i][j]>prev[i][k]+prev[k][j]:
                    next[i][j] = prev[i][k]+prev[k][j]
                    next_path[i][j] = path[k][j]
                else:
                    next[i][j] = prev[i][j]
                    next_path[i][j] = path[i][j]
        # 
        prev = next
        path = next_path
        # print(prev)
    print('---------------path---------------')
    print(next_path)
    # retutn prev

d = [
    [0, 3, 8, MAX_DIS, -4],
    [MAX_DIS, 0, MAX_DIS, 1, 7],
    [MAX_DIS, 4, 0, MAX_DIS, MAX_DIS],
    [2, MAX_DIS, -5, 0, MAX_DIS],
    [MAX_DIS, MAX_DIS, MAX_DIS, 6, 0]
]

if __name__ == '__main__':
    floyd_warshall(d)
    pass