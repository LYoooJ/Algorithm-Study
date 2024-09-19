from collections import defaultdict

def solution(participant, completion):
    players = defaultdict(int)
    
    for player in participant:
        players[player] += 1
    for player in completion:
        players[player] -= 1
        if players[player] == 0:
            del players[player]
            
    return list(players.keys())[0]
    