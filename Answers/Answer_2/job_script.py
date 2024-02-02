import subprocess
import multiprocessing as mp
import time
import random
import sys

n = 10 #number of parallel jobs

if len(sys.argv) == 2:
    n = int(sys.argv[1])

def hello_world(process_number: int, hello_number: str):
    result = subprocess.run(["./Hello_world", hello_number], capture_output=True, text=True)

    with open(f"./outputs/output_{str(process_number)}.txt", "w") as file:
        file.write(result.stdout)
    return process_number, time.time()


max_workers = max(mp.cpu_count()-1,1)
with mp.Pool(processes=max_workers) as pool:
    results = []
    for i in range(n):
        results.append(pool.apply_async(hello_world, (i, str(random.randint(1, 100)),)))
    for result in results:
        print(f"Process {result.get()[0]} finished at time {result.get()[1]}")
