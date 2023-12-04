import heapq

def solution(alp, cop, problems):
    q = []
    heapq.heappush(q,[0,alp,cop]) 
    need_alp = 0
    need_cop = 0
    for problem in problems:
        if need_alp < problem[0]:
            need_alp = problem[0]

        if need_cop < problem[1]:
            need_cop = problem[1]
    visited = dict()
    
    
    while True:
        cur_cost, cur_alp, cur_cop = heapq.heappop(q)
        if cur_alp >= need_alp and cur_cop >= need_cop:
            return cur_cost
        if (cur_alp, cur_cop) in visited and visited[(cur_alp, cur_cop)] <= cur_cost:
            continue
        visited[(cur_alp, cur_cop)] = cur_cost
        heapq.heappush(q,[cur_cost+1,min(cur_alp+1, need_alp),cur_cop])
        heapq.heappush(q,[cur_cost+1,cur_alp,min(cur_cop+1, need_cop)])

        for problem in problems:
            alp_req, cop_req, alp_rwd, cop_rwd , cost = problem
            if cur_alp >= alp_req and cur_cop >= cop_req:
                new_alp = min(cur_alp + alp_rwd, need_alp)
                new_cop = min(cur_cop + cop_rwd, need_cop)
                heapq.heappush(q,[cur_cost+cost,new_alp,new_cop])