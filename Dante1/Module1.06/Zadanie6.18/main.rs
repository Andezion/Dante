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

    let mut matrix_b: [[i32; 5]; 5] = [[0; 5]; 5];
    println!("Enter: ");
    for i in 0..5 {
        for j in 0..5 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Err");
            matrix_b[i][j] = input.trim().parse().expect("err");

            if matrix_a[i][j] == matrix_b[i][j] {
                continue;
            }
            else {
                matrix_a[i][j] = matrix_b[i][j];
            }
        }
    }

    for i in 0..5 {
        for j in 0..5 {
            print!("{} ", matrix_a[i][j]);
        }
        println!();
    }
}
