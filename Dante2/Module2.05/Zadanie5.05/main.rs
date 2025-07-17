mod matrix_utils;
use regex::Regex;

fn main() {
    let mut input: String = String::new();

    println!("Enter data: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let re = Regex::new(r"(\d+)\s+(\d+)").expect("Incorrect REGEX");
    if let Some(caps) = re.captures(&input) {
        let width: i32 = caps[1].parse().expect("Incorrect width parse");
        let height: i32 = caps[2].parse().expect("Incorrect height parse");

        if width <= 0 || height <= 0 {
            panic!("Incorrect input data");
        }

        let mut m: matrix_utils::MatrixT = Default::default();
        match matrix_utils::matrix_create(&mut m, width, height) {
            Err(1) => panic!("Incorrect input"),
            _other => {},
        }

        matrix_utils::matrix_display(&m);

        println!("Enter matrix: ");
        match matrix_utils::matrix_read(&mut m) {
            Err(1) => panic!("Incorrect matrix in matrix_read"),
            _other => {},
        }

        matrix_utils::matrix_display(&m);

        match matrix_utils::matrix_transpose(&m) {
            Err(1) => panic!("Incorrect input data"),
            Err(2) => panic!("Incorrect create"),
            Ok(tm) => matrix_utils::matrix_display(&tm),
            _other => panic!("I don't know what to do now"),
        }
    }
}
