def sjf_preemptive():
    import sys

    def validate_input(prompt, is_float=False):
        while True:
            try:
                value = float(input(prompt)) if is_float else int(input(prompt))
                if value < 0:
                    raise ValueError("Value cannot be negative.")
                return value
            except ValueError as e:
                print("Invalid input. Please enter a valid positive number.")

    # Input number of processes
    n = validate_input("Enter the number of processes: ")

    # Input process details
    processes = []
    for i in range(n):
        print(f"\nEnter details for Process {i + 1}:")
        arrival_time = validate_input("Arrival Time: ")
        burst_time = validate_input("Burst Time: ")
        processes.append({
            "pid": i + 1,
            "arrival_time": arrival_time,
            "burst_time": burst_time,
            "remaining_time": burst_time,  # Used for preemptive scheduling
        })

    # Initialize tracking variables
    time = 0
    completed = 0
    avg_waiting_time = 0
    avg_turnaround_time = 0
    avg_response_time = 0
    waiting_times = [0] * n
    turnaround_times = [0] * n
    response_times = [-1] * n

    # Main logic for SJF Preemptive
    while completed < n:
        # Find process with the shortest remaining time at the current time
        current_process = None
        min_remaining_time = sys.maxsize

        for p in processes:
            if (
                p["arrival_time"] <= time
                and p["remaining_time"] > 0
                and p["remaining_time"] < min_remaining_time
            ):
                current_process = p
                min_remaining_time = p["remaining_time"]

        if current_process is None:
            time += 1
            continue

        # Process the selected process for 1 time unit
        if response_times[current_process["pid"] - 1] == -1:
            response_times[current_process["pid"] - 1] = time - current_process["arrival_time"]

        current_process["remaining_time"] -= 1
        time += 1

        # If process is completed
        if current_process["remaining_time"] == 0:
            completed += 1
            pid = current_process["pid"] - 1

            turnaround_times[pid] = time - current_process["arrival_time"]
            waiting_times[pid] = turnaround_times[pid] - current_process["burst_time"]

    # Calculate averages
    avg_waiting_time = sum(waiting_times) / n
    avg_turnaround_time = sum(turnaround_times) / n
    avg_response_time = sum(response_times) / n

    # Print results
    print("\nProcess Details and Times:")
    print("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time")
    for i, p in enumerate(processes):
        print(
            f"{p['pid']}\t{p['arrival_time']}\t\t{p['burst_time']}\t\t{waiting_times[i]}\t\t{turnaround_times[i]}\t\t{response_times[i]}"
        )

    print("\nAverages:")
    print(f"Average Waiting Time: {avg_waiting_time:.2f}")
    print(f"Average Turnaround Time: {avg_turnaround_time:.2f}")
    print(f"Average Response Time: {avg_response_time:.2f}")

# Run the program
sjf_preemptive()
