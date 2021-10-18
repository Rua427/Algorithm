#두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
# 이문제는 EOF 처리 방법을 알고 있는지 확인하는 문제임

while True:
    try:
        num1, num2 = map(int, input().split())
        print(num1 + num2)
    except:
        break
