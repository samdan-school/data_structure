from PIL import Image


def main():
    try:
        # Relative Path
        img = Image.open("./sakura.jpg")

        img.show()
    except IOError:
        pass


if __name__ == "__main__":
    main()
