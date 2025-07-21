fn main() {
    let mut matrix: [[i32; 5]; 5] = [[0; 5]; 5];
    let mut vector: [i32; 5] = [0; 5];

    let mut input: String = String::new();
    println!("Enter: ");

    for i in 0..5 {
        for j in 0..5 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect input");
            matrix[i][j] = input.trim().parse().expect("Incorrect");

            vector[j] = vector[j] + matrix[i][j];
        }
    }

    let mut max: i32 = vector[0];
    let mut need: usize = 0;

    for i in 1..5 {
        if max < vector[i] {
            max = vector[i];
            need = i;
        }
    }

    for i in 0..5 {
        if vector[i] == max {
            for j in 0..5 {
                print!("{} ", matrix[j][need]);
            }
            println!();
        }
    }
}
