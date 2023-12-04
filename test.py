def solution(rc, operations):
    r = len(rc)
    c = len(rc[0])

    for op in operations:
        if op == "Rotate":
            top = rc[0][1:-1]
            right = [row[-1] for row in rc[1:-1]]
            bottom = rc[-1][-2:0:-1]
            left = [row[0] for row in rc[-2:0:-1]]

            rotated_top = [rc[0][0]] + top
            rotated_right = right + [rc[0][-1]]
            rotated_bottom = [rc[-1][-1]] + bottom
            rotated_left = left + [rc[-1][0]]

            rc[0] = [rotated_left[0]] + rotated_top + [rotated_right[0]]
            for i in range(1, len(rc) - 1):
                rc[i] = [rotated_left[i]] + rc[i][1:-1] + [rotated_right[i]]
            rc[-1] = [rotated_left[-1]] + rotated_bottom + [rotated_right[-1]]


        elif op == "ShiftRow":
            tmp_row = rc[-1]
            for i in range(r-1, 0, -1):
                rc[i] = rc[i-1]
            rc[0] = tmp_row

    return rc
