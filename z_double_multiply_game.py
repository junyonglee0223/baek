import random
import time
import threading
import sys

# 전역 플래그
stop_timer = False

def timer(start_time):
    """시간을 계속 출력하는 쓰레드"""
    while not stop_timer:
        elapsed = time.time() - start_time
        minutes = int(elapsed // 60)
        seconds = int(elapsed % 60)
        millis = int((elapsed - int(elapsed)) * 1000)

        time.sleep(0.05)  # 0.05초마다 업데이트
        sys.stdout.write(f"\r⏱ {minutes:02d}:{seconds:02d}.{millis:03d}")
        sys.stdout.flush()

def play_game():
    global stop_timer
    problem_num = 1

    # 10문제까지만 반복
    while problem_num <= 10:
        print("-------------------------------------")
        a = random.randint(10, 100)
        b = random.randint(10, 100)

        print(f"\n{problem_num}: {a} * {b} = ?")

        start_time = time.time()
        stop_timer = False

        # 타이머 쓰레드 시작
        t = threading.Thread(target=timer, args=(start_time,))
        t.daemon = True
        t.start()

        while True:  
            try:
                answer = int(input("\n정답 입력: "))
            except ValueError:
                print("숫자로 입력하세요.")
                continue

            if answer == a * b:
                stop_timer = True
                t.join(timeout=0.1)  # 타이머 쓰레드 정리
                problem_num += 1
                break
            else:
                pass
                #print("틀렸습니다. 다시 입력하세요.")
        print("\n")

    print("\n게임 종료! 10문제를 모두 풀었습니다 🎉")

if __name__ == "__main__":
    print("곱셈 게임 시작! (Ctrl+C 로 종료)")
    play_game()
