def solution(phone_book):
    phone_book = sorted(phone_book)
    
    i = 0
    while i < len(phone_book) - 1:
        if phone_book[i] == phone_book[i + 1][:len(phone_book[i])]:
            return False
        i += 1
    
    return True