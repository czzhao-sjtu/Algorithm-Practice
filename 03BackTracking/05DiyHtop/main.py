import psutil

def BackTrack(process: psutil.Process, level: int = 0) -> None:
    try:
        print('   ' * level, f'- process id:{process.pid:<6d} {process.name()}')
    except:
        print('   ' * level, f'- process id:{process.pid:<6d}')

    for sub_process in process.children():
        BackTrack(sub_process, level+1)
    
    return

def main():
    root = psutil.Process(1)
    BackTrack(root, 0)

if __name__ == "__main__":
    main()