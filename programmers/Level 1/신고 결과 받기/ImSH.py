def solution(id_list: list, report: list, k: int) -> list:
    answer = [0] * len(id_list)
    
    arr = [[0] * len(id_list) for i in range(len(id_list))]
    total = [0] * len(id_list)

    for str in report:
        split_id = str.split()
        reporter = id_list.index(split_id[0])
        reported = id_list.index(split_id[1])
        arr[reporter][reported] += 1

    for i in range(len(id_list)):
        for j in range(len(id_list)):
            if arr[j][i] > 0:
                total[i] += 1
    
    for i in range(len(id_list)):
        if total[i] // k > 0:
            for j in range(len(id_list)):
                if arr[j][i] > 0:
                    answer[j] += 1

    return answer