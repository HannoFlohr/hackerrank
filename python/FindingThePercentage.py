if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        line = input().split()
        name, scores = line[0], line[1:]
        scores = map(float, scores)
        student_marks[name] = scores
    query_name = input()

    counter = 0
    avg = 0.0
    for x in student_marks[query_name]:
        counter += 1
        avg += x

    avg /= counter

    print( "{:.{}f}".format( avg, 2 ) )

#https://www.hackerrank.com/challenges/finding-the-percentage/problem