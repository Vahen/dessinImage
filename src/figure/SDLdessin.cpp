#include <figure/SDLdessin.hpp>
#include <cmath>

namespace figure {

    SDLdessin::SDLdessin(int width, int height) : 
		m_width(width),
		m_height(height),
		m_window(nullptr),
		m_renderer(nullptr) {
    }

    SDLdessin::SDLdessin(const SDLdessin &) : SDLdessin(800,600) {

    }

    SDLdessin &SDLdessin::operator=(const SDLdessin &) {
		// todo copy-swap idiom
        return *this;
    }

	SDLdessin::~SDLdessin() {
		SDL_DestroyWindow(m_window);
	};

    void SDLdessin::initialise() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw std::runtime_error("SDL could not be initialized: " + string(SDL_GetError()));
		}
        if (SDL_CreateWindowAndRenderer(m_width, m_height, 0, &m_window, &m_renderer) < 0) {
			throw std::runtime_error("Window could not be created: " + string(SDL_GetError()));
		}
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    }

// todo
    void SDLdessin::dessineLigne(const Point &p1, const Point &p2) const {
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(m_renderer,
                           static_cast<int>(std::round(p1.getX())), static_cast<int>(std::round(p1.getY())),
                           static_cast<int>(std::round(p2.getX())), static_cast<int>(std::round(p2.getY())));
        SDL_RenderPresent(m_renderer);

    }

    void SDLdessin::dessineCercle(const Point &centre, float rayon) const {
        draw_circle(m_renderer,
                    static_cast<int>(std::round(centre.getX())), static_cast<int>(std::round(centre.getY())),
                    static_cast<int>(std::round(rayon)),
                    255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderPresent(m_renderer);
    }

    void SDLdessin::set_pixel(SDL_Renderer *rend, int x, int y, int r, int g, int b, int a) const {
        SDL_SetRenderDrawColor(rend,
			static_cast<Uint8>(r), static_cast<Uint8>(g), static_cast<Uint8>(b), static_cast<Uint8>(a));
        SDL_RenderDrawPoint(rend, x, y);
    }

    void SDLdessin::draw_circle(SDL_Renderer *surface,
                                int n_cx, int n_cy, int radius,
                                int r, int g, int b, int a) const {
        auto error = (double) -radius;
        double x = (double) radius - 0.5;
        auto y = 0.5;
        double cx = n_cx - 0.5;
        double cy = n_cy - 0.5;

        while (x >= y) {
            set_pixel(surface, (int) (cx + x), (int) (cy + y), r, g, b, a);
            set_pixel(surface, (int) (cx + y), (int) (cy + x), r, g, b, a);

            if (x != 0) {
                set_pixel(surface, (int) (cx - x), (int) (cy + y), r, g, b, a);
                set_pixel(surface, (int) (cx + y), (int) (cy - x), r, g, b, a);
            }

            if (y != 0) {
                set_pixel(surface, (int) (cx + x), (int) (cy - y), r, g, b, a);
                set_pixel(surface, (int) (cx - y), (int) (cy + x), r, g, b, a);
            }

            if (x != 0 && y != 0) {
                set_pixel(surface, (int) (cx - x), (int) (cy - y), r, g, b, a);
                set_pixel(surface, (int) (cx - y), (int) (cy - x), r, g, b, a);
            }

            error += y;
            ++y;
            error += y;

            if (error >= 0) {
                --x;
                error -= x;
                error -= x;
            }
        }
    }

    void SDLdessin::dessinePolygone(const vector<Point> &points) const {
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        for (unsigned int i = 0; i < points.size() - 1; i++) {
            int x1 = static_cast<int>(std::round(points[i].getX()));
            int y1 = static_cast<int>(std::round(points[i].getY()));;
            int x2 = static_cast<int>(std::round(points[i + 1].getX()));;
            int y2 = static_cast<int>(std::round(points[i + 1].getY()));;
            SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
        }
        SDL_RenderPresent(m_renderer);
    }

    void SDLdessin::attendTouche() const {
        bool done = false;
        while (!done) {
            SDL_Event event{};
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_KEYDOWN) {
                    done = true;
                }
                if (event.type == SDL_QUIT) {
                    exit(0);
                }
            }
        }
    }

    void SDLdessin::nettoie() const {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(m_renderer);
    }

}

