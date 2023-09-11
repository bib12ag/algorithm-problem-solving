def solution(n, left, right):
    answer = []
    
    lr = (left // n) + 1
    lc = (left % n) + 1
    rr = (right // n) + 1
    rc = (right % n) + 1
    
    if lr == rr:
        if lr < lc:
            answer += [i for i in range(lc, rc + 1)]
        elif rc <= rr:
            answer += [rr] * (rc - lc + 1)
        else:
            answer += [lr] * (lr - lc + 1)
            answer += [i for i in range(rr + 1, rc + 1)]
    else:
        if lr < lc:
            answer += [i for i in range(lc, n + 1)]
        else:
            answer += [lr] * (lr - lc + 1)
            answer += [i for i in range(lr + 1, n + 1)]
        
        for num in range(lr + 1, rr):
            answer += [num] * num
            answer += [i for i in range(num + 1, n + 1)]
            
        if rr >= rc:
            answer += [rr] * rc
        else:
            answer += [rr] * rr
            answer += [i for i in range(rr + 1, rc + 1)]
    
    return answer
