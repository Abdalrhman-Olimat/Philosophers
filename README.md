# 🧠 Philosophers Project - 42 Amman

A multithreaded simulation of the classic **Dining Philosophers Problem**, implemented in **C** as part of the 42 Network curriculum.

## 📝 Project Description

The goal of this project is to explore **multithreading**, **mutexes**, and **concurrency control** through a well-known synchronization problem.

Imagine 5 philosophers sitting at a table. They each alternate between thinking 🧠 and eating 🍝. But to eat, a philosopher needs two forks — one on their left and one on their right. There are only 5 forks total, shared between them.

This setup easily leads to:
- Deadlocks 🔒
- Starvation 🥀
- Race conditions 🏁

Your job? **Prevent chaos.**

## ⚙️ How It Works

Each philosopher is represented by a thread. The simulation ensures:
- Philosophers pick up forks only if both are available.
- No two philosophers use the same fork at the same time.
- Death by starvation is detected and avoided (optional in bonus).

To achieve this, we use:
- `pthread` library for thread creation and management
- `mutex`es to control fork access
- Accurate time tracking with `gettimeofday` or similar functions

## 🧪 How to Run

### 1. Clone the repo:
```bash
git clone https://github.com/your-username/philosophers.git
cd philosophers
```
2. Build the project:

```bash
cd philo
make
```
3. Run it:
```bash

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```bash


./philo 5 800 200 200
```
✅ Rules Recap
A philosopher dies if they don’t eat within time_to_die.

Philosophers eat for time_to_eat and sleep for time_to_sleep.

The simulation ends when all philosophers eat number_of_times_each_philosopher_must_eat (if given).

⭐ Bonus (philo_bonus/)
Uses processes instead of threads.

Uses semaphores instead of mutexes.

Implements monitoring in a separate process.

Handles philosopher death properly across forks.

🧠 What I Learned
Core concepts of concurrency and thread safety

How to prevent deadlocks and starvation

Writing clean and modular multithreaded C code

How OS-level scheduling and timing works in practice



👤 Author
Abdalrhman
LinkedIn | GitHub

📚 Part of the 42 Amman curriculum.
Thanks to the amazing peers who helped me debug at 3AM 😅

<img width="640" height="664" alt="image" src="https://github.com/user-attachments/assets/17266e3c-3eaa-4881-a792-d001f2b94e6e" />

Let me know if you'd like help filling in specific links (GitHub, LinkedIn) or want me to include a bash script to run tests, handle input validation, or even add a screenshot/GIF section with instructions.
