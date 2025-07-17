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

pub fn matrix_create_struct(width: i32, height: i32) -> Result<MatrixT, String> {
    if height <= 0 || width <= 0 {
        return Err("Width and height must be positive integers.".to_string());
    }

    let mut m: MatrixT = Default::default();

    match matrix_create(&mut m, width, height) {
        Ok(0) => {}
        _other => return Err("Error while creating matrix".to_string()),
    }

    Ok(m)
}

pub fn matrix_transpose(m: & MatrixT) -> Result<MatrixT, i32> {
    if m.height <= 0 || m.width <= 0 {
        return Err(1);
    }

    let mut tm: MatrixT = Default::default();
    match matrix_create(&mut tm, m.height, m.width) {
        Err(1) => return Err(2),
        _ => {}
    };

    for i in 0..m.height {
        for j in 0..m.width {
            tm.ptr[j as usize][i as usize] = m.ptr[i as usize][j as usize];
        }
    }

    Ok(tm)
}

// pub fn matrix_save_b(m: & MatrixT, filename: & String) -> i32 {
//
// }

// pub fn matrix_save_t(m: & MatrixT, filename: & String) -> i32 {
//
// }
