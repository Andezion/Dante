fn is_prime(a: i32) -> i32  {
    let mut counter: usize = 0;
    if a == 0 || a == 1 || a < 0 {
        return 0;
    }

    for i in 1..=i32::isqrt(a) {
        if a % i == 0 {
            counter += 1;
        }
    }
    if counter <= 2 {
        return 1;
    }

    0
}

fn basic_cycle(mut matrix: &[[i32; 5]; 5], mut max_primes: usize, mut counter: usize) {
    for i in 0..=2 {
        for j in 0..=2 {
            let mut helper: usize = 0;

            for x in 0..3 {
                for y in 0..3 {
                    if is_prime(matrix[i + x][j + y]) == 1
                    {
                        helper += 1;
                    }
                }
            }

            if helper > max_primes {
                max_primes = helper;
                counter = 1;
            }
            else if max_primes == helper {
                counter += 1;
            }
        }
    }
}

fn cool_cycle(mut matrix: &[[i32; 5]; 5], mut max_primes: usize, mut counter: usize) {
    for i in 0..=2 {
        for j in 0..=2 {
            let mut helper: usize = 0;

            for x in 0..3 {
                for y in 0..3 {
                    if is_prime(matrix[i + x][j + y]) == 1
                    {
                        helper += 1;
                    }
                }
            }

            if max_primes == helper {
                println!("{} {}", i + 1, j + 1);
            }
        }
    }
}

fn main() {
    let mut input = String::new();

    let mut matrix: [[i32; 5]; 5] = [[0; 5]; 5];

    println!("Enter: ");
    for i in 0..5 {
        for j in 0..5 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Error");
            matrix[i][j] = input.trim().parse().expect("Error");
        }
    }

    let max_primes: usize = 0;
    let counter: usize = 0;

    basic_cycle(&matrix, max_primes, counter);

    if max_primes == 0 {
        println!("0");
    }
    else {
        println!("{}", counter);
        cool_cycle(&matrix, max_primes, counter);
    }
}
