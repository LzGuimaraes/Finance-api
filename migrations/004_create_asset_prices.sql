CREATE TABLE asset_prices (
    id BIGSERIAL PRIMARY KEY,
    asset_ticker VARCHAR(20) NOT NULL,
    price DECIMAL(15,2) NOT NULL,
    price_date DATE NOT NULL,

    CONSTRAINT fk_asset_price
        FOREIGN KEY(asset_ticker)
        REFERENCES assets(ticker)
        ON DELETE CASCADE
);