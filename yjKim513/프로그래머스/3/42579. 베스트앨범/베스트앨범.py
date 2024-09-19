def solution(genres, plays):
    genre_info = {}
    for i in range(len(genres)):
        if genres[i] not in genre_info.keys():
            genre_info[genres[i]] = {"total": plays[i], "songs": [i]}
        else:
            genre_info[genres[i]]["total"] += plays[i]
            genre_info[genres[i]]["songs"].append(i)
    
    genre_list = sorted(genre_info.keys(), key=lambda x: genre_info[x]["total"], reverse=True)
    answer = []
    for genre in genre_list:
        if len(genre_info[genre]["songs"]) < 2:
            answer.extend(genre_info[genre]["songs"])
        else:
            genre_info[genre]["songs"].sort(key=lambda x:plays[x], reverse=True)
            answer.append(genre_info[genre]["songs"][0])
            answer.append(genre_info[genre]["songs"][1])
            
    return answer