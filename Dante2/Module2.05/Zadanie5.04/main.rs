use regex::Regex;

#[derive(Default)]
pub struct MatrixT {
    ptr: Vec<Vec<i32>>,
    width: i32,
    height: i32,
}

pub fn matrix_create(m: &mut MatrixT, width: i32, height: i32) -> Result<i32, i32> {
    if height <= 0 || width <= 0 {
        return Err(1);
    }

    m.width = width;
    m.height = height;
    m.ptr = vec![vec![0; width as usize]; height as usize];

    Ok(0)
}

pub fn matrix_read(m: &mut  MatrixT) -> Result<i32, i32> {
    if m.height <= 0 || m.width <= 0 {
        return Err(1);
    }

    let mut input: String = String::new();
    for i in 0..m.height {
        for j in 0..m.width {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect input");
            m.ptr[i as usize][j as usize] = input.trim().parse().expect("Incorrect parse");
        }
    }

    Ok(0)
}

pub fn matrix_display(m: & MatrixT) {
    if m.width <= 0 || m.height <= 0 {
        return;
    }

    println!();
    for i in 0..m.height {
        for j in 0..m.width {
            print!("{} ", m.ptr[i as usize][j as usize])
        }
        println!();
    }
    println!();
}


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

        let mut m: MatrixT = Default::default();
        match matrix_create(&mut m, width, height) {
            Err(1) => panic!("Incorrect input"),
            _other => {},
        }

        matrix_display(&m);

        println!("Enter matrix: ");
        match matrix_read(&mut m) {
            Err(1) => panic!("Incorrect matrix in matrix_read"),
            _other => {},
        }

        matrix_display(&m);
    }
}
