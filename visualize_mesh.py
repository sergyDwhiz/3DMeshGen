import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection

def read_obj(filename):
    vertices = []
    faces = []

    with open(filename, 'r') as file:
        for line in file:
            if line.startswith('v '):
                parts = line.split()
                vertices.append([float(parts[1]), float(parts[2]), float(parts[3])])
            elif line.startswith('f '):
                parts = line.split()
                faces.append([int(parts[1])-1, int(parts[2])-1, int(parts[3])-1])

    return vertices, faces

def plot_mesh(vertices, faces):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    mesh = Poly3DCollection([[vertices[idx] for idx in face] for face in faces], alpha=0.5, edgecolor='k')
    ax.add_collection3d(mesh)

    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    ax.auto_scale_xyz([min(v[0] for v in vertices), max(v[0] for v in vertices)],
                      [min(v[1] for v in vertices), max(v[1] for v in vertices)],
                      [min(v[2] for v in vertices), max(v[2] for v in vertices)])

    plt.show()

if __name__ == '__main__':
    vertices, faces = read_obj('data/output_mesh.obj')
    plot_mesh(vertices, faces)