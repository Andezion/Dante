fn main() {
    let mut array: [[i32; 5]; 5] = [[0; 5]; 5];
    let mut input: String = String::new();

    println!("Enter: ");
    for i in 0..5 {
        for j in 0..5 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect");
            array[i][j] = input.trim().parse().expect("Incorrect");
        }
    }

    let mut max: i32 = i32::MAX;
    for i in 0..5 {
        for j in 0..5 {
            for k in 0..5 {
                for l in 0..5 {
                    if i != k || j != l {
                        let sum: i32 = array[i][j] + array[k][l];
                        if sum > max {
                            max = sum;
                        }
                    }
                }
            }
        }
    }

    let mut counter: i32 = 0;
    for i in 0..5 {
        for j in 0..5 {
            for k in 0..5 {
                for l in 0..5 {
                    if (i != k || j != l) && (i * 5 + j < k * 5 + l) {
                        let sum: i32 = array[i][j] + array[k][l];
                        if sum == max {
                            counter += 1;
                        }
                    }
                }
            }
        }
    }

    println!("\n{} {}", max, counter);

    for i in 0..5 {
        for j in 0..5 {
            for k in 0..5 {
                for l in 0..5 {
                    if (i != k || j != l) && (i * 5 + j < k * 5 + l) {
                        let sum: i32 = array[i][j] + array[k][l];
                        if sum == max {
                            println!("{i} {j} {k} {l}");
                        }
                    }
                }
            }
        }
    }
}
