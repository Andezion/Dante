fn main() {
    let mut array: Vec<Vec<i32>> = vec![vec![0; 10]; 10];
    // for i in 0..10 {
    //     array[i] = vec![0; 10];
    // }

    for i in 0..10 {
        for j in 0..10 {
            array[i][j] = ((i + 1) * (j + 1)) as i32;
        }
    }
    for i in 0..10 {
        for j in 0..10 {
            print!("{:4}", array[i][j]);
        }
        println!();
    }
}
