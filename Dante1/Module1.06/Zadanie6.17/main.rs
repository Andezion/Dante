fn main() {
    let mut array: [[i32; 5]; 5] = [[0; 5]; 5];

    let mut input: String = String::new();
    println!("Enter: ");

    let mut sum: i32 = 0;
    for i in 0..5 {
        for j in 0..5 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect");

            array[i][j] = input.trim().parse().expect("Incorrect");

            if i == 4 || j == 4 || i == 0 || j == 0 {
                sum = sum + array[i][j];
            }
        }
    }

    println!("{}", sum);
}
