#[derive(Default)]
struct DateT {
    day: i32,
    month: i32,
    year: i32
}

fn read(d: &mut DateT) -> &mut DateT {
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Err");

    let v: Vec<i32> = input.split(' ').map(|x|->i32{x.parse().unwrap()}).collect();
    set_date(d, v[0], v[1], v[2]);
    d
}

fn set_date(d: &mut DateT, day: i32, month: i32, year: i32) -> &mut DateT {
    d.day = day;
    d.month = month;
    d.year = year;

    d
}

fn validate(d: & DateT) -> i32 {
    if d.day <= 0 || d.month <= 0 || d.year < 0 ||
        d.day > 31 || d.month > 12 {
        return 0;
    }

    let day_array: [i32; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let month_array: [i32; 12] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
    for i in 0..12 {
        if d.month == month_array[i] && day_array[i] < d.day{
            return 0;
        }
    }

    if d.month == 2 {
        if (d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0)
        {
            if d.day > 29
            {
                return 0;
            }
        }
        else
        {
            if d.day > 28
            {
                return 0;
            }
        }
    }

    1
}

fn show(d: & DateT) {
    if d.day < 10 {
        if d.month < 10 {
            if d.year < 1000 {
                println!("0{}-0{}-0{}\n", d.day, d.month, d.year);
            }
            if d.year >= 1000 {
                println!("0{}-0{}-{}\n", d.day, d.month, d.year);
            }
        }
        else
        {
            if d.year < 1000 {
                println!("0{}-{}-0{}\n",d.day,d.month,d.year);
            }
            if d.year >= 1000 {
                println!("0{}-{}-{}\n",d.day,d.month,d.year);
            }
        }
    }
    else {
        if d.month < 10 {
            if d.year < 1000 {
                println!("{}-0{}-0{}\n",d.day,d.month,d.year);
            }
            if d.year >= 1000 {
                println!("{}-0{}-{}\n",d.day,d.month,d.year);
            }
        }
        else {
            if d.year < 1000 {
                println!("{}-{}-0{}\n",d.day,d.month,d.year);
            }
            if d.year >= 1000 {
                println!("{}-{}-{}\n",d.day,d.month,d.year);
            }
        }
    }
}

fn main() {
    let mut d: DateT = Default::default();
    read(&mut d);

    let res: i32 = validate(&d);
    if res == 0 || res == -1 {
        panic!("Incorrect");
    }
    else {
        println!("Correct!");
        show(&d);
    }
}
