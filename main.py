import pywavefront as wf


def load_scene() -> None:
    """ Loads the example scene. """
    pass


if __name__ == '__main__':
    teapot = wf.Wavefront('objects/teapot/teapot.obj')
    teapot.parse()
