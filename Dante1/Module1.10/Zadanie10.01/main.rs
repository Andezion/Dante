fn main()
{
    let mut integer_number: i32 = 5;
    let mut double_number: f64 = 65.5;
    let mut char_letter: char = 'A';

    let on_integer_number: &mut i32 = &mut integer_number;
    let on_double_number: &mut f64 = &mut double_number;
    let on_char_letter: &mut char = &mut char_letter;

    println!("{:p} {} {}", on_integer_number, on_double_number, on_char_letter);

    *on_integer_number = 6;
    *on_double_number = 4.5;
    *on_char_letter = 'S';

    println!("{} {} {}", on_integer_number, *on_double_number, *on_char_letter);
}
