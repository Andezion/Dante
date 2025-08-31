fn main() {
    let mut input: String = String::new();

    let mut matrix_a: [[i32; 5]; 5] = [[0; 5]; 5];
    println!("Enter: ");
    for i in 0..5 {
        for j in 0..5 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Err");
            matrix_a[i][j] = input.trim().parse().expect("err");
        }
    }

    println!("Enter: ");
    let mut matrix_b: [[i32; 5]; 5] = [[0; 5]; 5];
    for i in 0..5 {
        for j in 0..5 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Err");
            matrix_b[i][j] = input.trim().parse().expect("err");
        }
    }

    let mut helper: [i32; 25] = [0; 25];
    for i in 0..5 {
        let mut counter: i32 = 0;

        for j in 0..5 {
            for m in 0.. 5 {
                if matrix_a[j][i] == matrix_b[m][i] {
                    let mut temp: i32 = 1;
                    for n in 0..5 {
                        if helper[n] == matrix_a[j][i] {
                            temp = 0;
                            break;
                        }
                    }

                    if temp == 1 {
                        helper[counter as usize] = matrix_a[j][i];
                        counter += 1;
                    }
                }
            }
        }

        print!("{} ", counter);

        for f in 0..counter {
            print!("{} ", helper[f as usize]);
        }
        println!();
    }
}
