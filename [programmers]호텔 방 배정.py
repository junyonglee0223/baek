def solution(k, room_number):
    answer = []
    rooms = {}

    for room in room_number:
        i = room
        visited = [i]
        while i in rooms:
            i = rooms[i]
            visited.append(i)
        answer.append(i)
        for j in visited:
            rooms[j] = i + 1
         
    return answer
