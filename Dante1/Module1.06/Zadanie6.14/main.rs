fn main() {
    let mut array: [[i32; 5]; 5] = Default::default();
    let mut helper_1: [i32; 5] = [ -100, -100, -100, -100, -100 ];
    let mut helper_2: [i32; 5] = [ -100, -100, -100, -100, -100 ];

    let mut input: String = String::new();
    for i in 0..5 {
        for j in 0..5 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect");
            array[i][j] = input.trim().parse().expect("Incorrect input");

            if array[i][j] > helper_1[i] {
                helper_1[i] = array[i][j];
            }
            if array[i][j] > helper_2[j]
            {
                helper_2[j] = array[i][j];
            }
        }
    }

    for i in 0..5 {
        print!("{} ", helper_1[i]);
    }
    for i in 0..5 {
        print!("{} ", helper_2[i]);
    }
}
