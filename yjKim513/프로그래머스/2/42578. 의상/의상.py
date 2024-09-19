def solution(clothes):
    clothes_categorized = {}
    for item, category in clothes:
        if category not in clothes_categorized.keys():
            clothes_categorized[category] = 2
        else:
            clothes_categorized[category] += 1
    
    answer = 1
    for category in clothes_categorized.keys():
        answer *= clothes_categorized[category]
    
    return answer - 1
    
    