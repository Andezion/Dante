#[cfg(test)]
mod tests {
    use crate::test1;

    #[test]
    fn test_1() {
        let result = test1(2);
        assert_eq!(result, 2);
    }

    #[test]
    fn test_2() {
        let result = test1(0);
        assert_eq!(result, 0);
    }

    #[test]
    fn test_3() {
        let result = test1(-1);
        assert_eq!(result, -1);
    }

    #[test]
    fn test_4() {
        let result = test1(-12312);
        assert_eq!(result, -12312);
    }

    #[test]
    fn test_5() {
        let result = test1(10000);
        assert_eq!(result, 10000);
    }
}
