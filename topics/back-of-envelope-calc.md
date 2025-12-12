# Back of Envelope Calculations

> Back of envelope calculations are techniques used to make quick, rough estimates or calculations without the need for detailed data or complex tools. They are often used in various fields such as engineering, finance, and everyday problem-solving to get a general idea of a value or outcome.

- [Back of Envelope Calculations](#back-of-envelope-calculations)
  - [Key Concepts](#key-concepts)
  - [Examples](#examples)
    - [Building Twitter like System](#building-twitter-like-system)
    - [Building a Pastebin like System](#building-a-pastebin-like-system)
    - [Conversion Table](#conversion-table)

## Key Concepts

- **Approximation**: Back of envelope calculations rely on approximations and assumptions to simplify complex problems. The goal is to get a ballpark figure rather than an exact answer.
- **Simplified Models**: These calculations often use simplified models or formulas that capture the essence of the problem without delving into all the complexities.
- **Order of Magnitude**: The focus is often on determining the order of magnitude (e.g., tens, hundreds, thousands) rather than precise values.
- **Quick Estimation**: The primary purpose is to provide a quick estimate that can inform decisions or guide further analysis.
- **Use of Common Knowledge**: Back of envelope calculations often leverage common knowledge, rules of thumb, and easily accessible data.

## Examples

### Building Twitter like System

To estimate the cost of building a Twitter-like system, we can break down the components involved:

- **User Base**: Estimating the number of users are **`300 million`**.
  - From `300 million` users:
    - Assuming `25%` are active daily users: `150 million` daily active users.
    - Assuming each active user generates average `2` tweets per day: `25% * 2 = 0.5 tweets per user per day`.
    - Assuming at the peak hour, tweets are increases by `2` times tweets per user.
- Let's calculate the total number of tweets per day:

  - Total tweets per second = `150M DAU * 0.5 tweets/DAU * 2x scaling / 86400 seconds/day`
    - Actually we don't need to calculate exact number, just need to know the order of magnitude, and we use scientific notation to represent it.
      - **150 Million** -> `1.5 x 10^8`
      - **Seconds in a day** -> `24 x 60 x 60 = 86400 -> estimate as 100,000 -> 10^5`
      - So, total tweets per second = `1.5 x 10^8 * 0.5 * 2 / 10^5 = 1.5 x 10^3 = 1500 tweets per second`

- **Storage Requirements**: Estimating the storage needed for tweets.
  - Assuming `10%` of tweets contains images and average size of an image is `100kb`.
  - Assuming `1%` of tweets contains videos and average size of a video is `100mb`.
  - Assuming files are replicated `3` times for redundancy.
  - Assuming retention period is `5 years`.
- Let's calculate the total storage required for tweets per year:

  - Total tweets calculation `150 million DAU * 0.1 tweets with pictures x 100kb x 400 days in a year x 5 years * 3 replicas`
  - Using scientific notation:
    - **150 Million** -> `1.5 x 10^8`
    - **100kb** -> `1 x 10^5 bytes`
    - **400 days** -> `4 x 10^2`
    - **5 years** -> `5 x 10^0`
    - **3 replicas** -> `3 x 10^0`
  - So, total storage for images:
    - `1.5 x 10^8 * 0.1 * 1 x 10^5 * 4 x 10^2 * 5 x 10^0 * 3 x 10^0`
    - `= 1.5 * 0.1 * 1 * 4 * 5 * 3 x 10^(8 + 5 + 2 + 0 + 0 + 0)`
    - `= 9 x 10^15 bytes = 9 PB -> 10^16 bytes`
  - Total storage for videos:
    - `1.5 x 10^8 x 0.01 x 1 x 10^8 x 4 x 10^2 x 5 x 10^0 x 3 x 10^0`
    - `= 1.5 * 0.01 * 1 * 4 * 5 * 3 x 10^(8 + 8 + 2 + 0 + 0 + 0)`
    - `= 9 x 10^15 bytes = 9 PB -> 10^16 bytes`

### Building a Pastebin like System

To estimate the cost of building a Pastebin-like system, we can break down the components involved:

- **User Base**: Estimating the number of users are **`10 million`**.
  - From `10 million` users:
    - Assuming `10%` are uploading daily users: `1 million` daily uploading users, `1 million` write requests per day.
      - Calculating per second: `1 million / 86400 seconds` estimate as `10^6 / 10^5 = 10 write per second`.
    - Assuming from `50` Requests user per day, `50 * 1 million = 50 million read requests per day`.
      - Calculating per second: `50 million / 86400 seconds` estimate as `5 x 10^7 / 10^5 = 500 read per second`.
- **Storage Requirements**: Estimating the storage needed for pastes.
  - Assuming average size of a paste is `10kb` -> `10^4 bytes`.
  - Assuming retention period is `5 years`.
  - Let's calculate the total storage required for pastes per year:
    - Total pastes calculation `1 million uploads per day x 10kb x 400 days in a year x 5 years`
    - Using scientific notation:
      - **1 million** -> `1 x 10^6`
      - **10kb** -> `1 x 10^4 bytes`
      - **400 days** -> `4 x 10^2`
      - **5 years** -> `5 x 10^0`
    - So, total storage for pastes:
      - `1 x 10^6 * 1 x 10^4 * 4 x 10^2 * 5 x 10^0`
      - `= 1 * 1 * 4 * 5 x 10^(6 + 4 + 2 + 0)`
      - `= 20 x 10^12 bytes = 2 x 10^13 bytes = 20 TB -> 10^13 bytes`
    - We will use 3 replicas for redundancy:
      - Total storage with replicas = `2 x 10^13 bytes * 3 = 6 x 10^13 bytes`
      - = `60 TB -> 10^14 bytes`
- **Bandwidth Requirements**: Estimating the bandwidth needed for read and write requests.

  - Incoming data per second (write): `10 write per second * 10kb = 10 * 10^4 bytes = 10^5 bytes per second = 0.1 MB/s`
  - Outgoing data per second (read): `500 read per second * 10kb = 500 * 10^4 bytes = 5 x 10^6 bytes per second = 5 MB/s`

- **Memory Requirements for Caching**: Estimating the memory needed for caching frequently accessed pastes.

  - Assuming `20%` of pastes are frequently accessed and we want to cache them.
  - We have:
    - `50 million read requests per day`
    - `10kb per paste`
    - `20% of pastes are frequently accessed`
  - So, total memory required for caching:
    - `50 million * 10kb * 0.2`
    - Using scientific notation:
      - **50 million** -> `5 x 10^7`
      - **10kb** -> `1 x 10^4 bytes`
      - **20%** -> `2 x 10^-1`
    - So, total memory for caching:
      - `5 x 10^7 * 1 x 10^4 * 2 x 10^-1`
      - `= 5 * 1 * 2 x 10^(7 + 4 - 1)`
      - `= 10 x 10^10 bytes = 10^11 bytes = 100 GB -> 10^11 bytes`

- **`Server Requirements`**:

  - Estimating the number of servers needed to handle the load, we have to check whether our application is CPU bound, Memory bound or I/O bound.
  - Assuming each server can handle `100 write requests per second` and `1000 read requests per second`.

- **CPU Bound**:
  - In **CPU Bound** we need to see number of `physical cores / time to process each request`.
  - For Example:
    - If CPU has `8 physical cores` and each request takes `0.5 s` to process.
    - Number of requests per second per server = `8 cores / 0.5 s = 16 requests per second`.
  - How many servers we need for handle requests:
    - For write requests: `10 write requests per second / 16 requests per second per server = ~1 server`.
    - For read requests: `500 read requests per second / 16 requests per second per server = ~32 servers`.

### Conversion Table

| Number Unit     | Memory Unit | Scientific Notation |
| --------------- | ----------- | ------------------- |
| Thousand (K)    | KB          | 10^3                |
| Million (M)     | MB          | 10^6                |
| Billion (B)     | GB          | 10^9                |
| Trillion (T)    | TB          | 10^12               |
| Quadrillion (Q) | PB          | 10^15               |
