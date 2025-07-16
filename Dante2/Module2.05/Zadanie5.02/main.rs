use regex::Regex;

fn create_array_2d(width: i32, height: i32) -> Result<Vec<Vec<i32>>, String> {
    if width <= 0 || height <= 0 {
        return Err("Width and height must be positive integers.".to_string());
    }

    let array: Vec<Vec<i32>> = vec![vec![0; width as usize]; height as usize];

    Ok(array)
}

fn display_array_2d(array: & Vec<Vec<i32>>, width: i32, height: i32) {
    if width < 0 || height < 0 {
        return;
    }
    for i in 0..height {
        for j in 0..width {
            print!("{} ", array[i as usize][j as usize]);
        }
        println!();
    }
}

fn main() {
    let mut input: String = String::new();
    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let re = Regex::new(r"(\d+)\s+(\d+)").expect("Incorrect REGEX");
    if let Some(caps) = re.captures(&input) {
        let width: i32 = caps[1].parse().expect("Incorrect width parse");
        let height: i32 = caps[2].parse().expect("Incorrect height parse");

        if width <= 0 || height <= 0 {
            panic!("Incorrect input data");
        }

        match create_array_2d(width, height) {
            Ok(mut array) => {
                println!("Enter: ");

                for i in 0..height {
                    for j in 0..width {
                        input.clear();
                        std::io::stdin().read_line(&mut input).expect("Incorrect input in array");
                        array[i as usize][j as usize] = input.trim().parse().expect("Incorrect parsing");
                    }
                }

                display_array_2d(&array, width, height);
            }
            Err(e) => eprintln!("Error: {}", e),
        }
    }
    else {
        panic!("Incorrect numbers");
    }
}
